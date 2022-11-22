# formatted print with underscores
def print_word(word):
    print(" ".join(word))
    return


# list conversion needed because str is not mutable I guess
def replace_underscores(answer, word, pos_list):
    l_word = list(word)
    
    for i in pos_list:
        l_word[i] = answer[i]

    word = "".join(l_word)    
    return word


def search_char(answer, letter):
    # search for matching letters
    cond = True
    idx = 0
    pos_list = []
    while cond:
        try:
            idx = answer.index(letter, idx)
            pos_list.append(idx)
            idx += 1
        except ValueError as e:
            cond = False
    return pos_list  


def load_words():
    f = open("parole.txt", "r")
    read = f.read()
    return read.split('\n')
