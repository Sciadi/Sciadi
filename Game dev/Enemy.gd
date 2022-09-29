extends RigidBody2D

class_name Enemy

#######################################################
# Per ogni nuova scena di un nuovo nemico basta solo:
#	- AnimatedSprite -> Rendere unico lo SpriteFrames e aggiungere i frames per le animazioni
#	- Particles2D -> Rendere unico e settare adeguatamente lo Shader del Process Material, settare la sprite giusta nello Shader Param 
#	- Script-> implementare (se necessario) adeguatamente la funzione die()
#				implementare (se necessario) correttamente set_fade_out_dir() 
#######################################################

var DamageText = preload("res://scenes/DamageText.tscn")
var gemScene = preload("res://scenes/objects/Gem.tscn")
onready var player = get_tree().get_nodes_in_group("player")[0]

var slug
var dir
var speed = 15
var canAttack = false
var velocity = Vector2.ZERO
var sprite
var died = false
var deathTime = 0.3
var receivesKnockback = true
var knockbackModifier = 5
var outside_screen = false

### Se il nemico fa parte di un orda dovrà comportarsi diversamente
var isHorde = false 

# Ogni figlio assegna i propri valori nella sua funzione ready 
var damage : float 
var hp 
var expAmount 


func _ready():
	# Momentaneamente le assegno da qua per non dover copia-incollare 
	# questo pezzo di codice in tutti i mostri:
	# Se le stats degli enemy si prendessero da un dict basterebbe implementare in questa classe 
	# una funzione assign_stats() che per ogni class figlia di questa assegna le stats nella ready 
	damage = 0.3
	hp = 10
	expAmount = rand_range(10, 15)
	
	# Setto la direzione iniziale
	if isHorde:
		dir = get_parent().hordeDirection.normalized()
	
	sprite = get_node("AnimatedSprite")
	get_node("AttackArea").connect("body_entered", self, "on_attack_area_entered")
	get_node("AttackArea").connect("body_exited", self, "on_attack_area_exited")


func _physics_process(delta):
	if hp <= 0:
		die()
	if not died:
		# comportamento nel caso di un orda
		if isHorde:
			if canAttack:
				attack_player(damage)
				update_movement(delta)
			else:
				update_movement(delta)
		# comportamento nel caso di un nemico normale
		else:
			if canAttack:
				attack_player(damage)
			else:
				update_movement(delta)


func update_movement(delta):
	if not player.died:
		sprite.play("walk")
		# Se l'enemy non fa parte dell'orda deve continuamente cambiare direzione e rivolgersi verso il player 
		if not isHorde: 
			dir = (player.global_position - global_position).normalized()
			face_player()
		
		global_position += dir * speed * delta
#		move_and_collide(dir * speed * delta)


func drop_loot(experience):
	var gemInstance = gemScene.instance()
	gemInstance.global_position = global_position
	gemInstance.expAmount = experience
	var collectiblesNode = get_tree().get_nodes_in_group("collectibles")[0]
	collectiblesNode.add_child(gemInstance)


func attack_player(damage_amount = 1):
	if not died:
		player.take_damage(damage_amount)


func take_damage(damageAmount):
	knockback(damageAmount)
	hp -= damageAmount
	$AnimationPlayer.play("hit")
	var damage_text = DamageText.instance()
	add_child(damage_text)
	damage_text.set_damage_label(damageAmount)


# Ogni figlio fa il suo override se necessario
func die():
	$CollisionShape2D.disabled = true
	died = true
	$AnimatedSprite.play("death")
	if $AnimatedSprite.frame == 3:
		$AnimationPlayer.play("fade_out")


func instance_death_timer():
	var deathTimer = Timer.new()
	deathTimer.connect("timeout", self, "on_death_timer_timeout")
	add_child(deathTimer)
	deathTimer.set_wait_time(deathTime)
	deathTimer.start()


func knockback(_receivedDamage):
	if receivesKnockback:
		var knockbackDir = player.global_position.direction_to(self.global_position)
		var knockback = knockbackDir * knockbackModifier
		
		global_position += knockback


# Chiamato dall'Animation player, setta la dirzione del particles 2D
func set_fade_out_dir():
	if dir.x < 0:
		$Particles2D.scale.x *= -1	


# Flippa la sprite verso il player 
# Override se necessario (in bat1 e bat2 perchè i bat sono flippati al contrario)
func face_player():
	if dir.x < 0:
		sprite.flip_h = true
	else:
		sprite.flip_h = false



###################################################################################################
#						FUNZIONI SCATENATE DA SIGNAL											  #
###################################################################################################

func on_death_timer_timeout():
	drop_loot(expAmount)
	queue_free()


# setta l'attack a true
func on_attack_area_entered(body):
	if body.name == "Player" and not died:
		if not isHorde:
			sprite.play("attack")
		player = body
		canAttack= true


# setta l'attack a false
func on_attack_area_exited(body):
	if body.name == "Player":
		canAttack = false
