import random 
from helpers import *

######################################### MAIN #######################################
# preparation
if __name__ == "__main__":
    lives : int = 5
    words : str = load_words()
    answer : str  = words[random.randint(0,len(words)-1)]
    print(answer)

    missing_letters = len(answer)
    word = "_"*len(answer) 

    print("Parola da trovare: ")
    print_word(word)


    # Game starts

    while (missing_letters > 0 and lives > 0):
        print("Vite ", lives)
        letter = input("Lettera: o soluzione: ->  ")

        # check entire word
        if len(letter)>1:
            if (letter == answer):
                word = answer
                print("Hai vinto")
                missing_letters = 0
                #print_word(word)
            else:
                lives-=1
                print("parola errata")
                if lives == 0:
                    print("Game over")
        else:
            pos_list = search_char(answer, letter)
            if (len(pos_list)==0):
                lives-=1
                print("lettera assente")
                if lives == 0:
                    print("Game over")
            elif letter not in word: 
                missing_letters -= len(pos_list)
                word = replace_underscores(answer, word, pos_list)
                if missing_letters == 0:
                    print("Hai vinto")
            
        print_word(word)



