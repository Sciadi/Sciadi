###
# multiclipboard list copy & paste, stores clibpoard content in a dict
# and makes you select what to paste 

import sys
import json
import clipboard
from .helper import print_dict, print_keys

SAVED_DATA_PATH = 'clipboard.json'
CLIPBOARD = 'clipboard'

# delete item from clipboard

def delete(filepath):
    try:
        with open(filepath, 'r') as f:
            data = json.load(f)
            f.close()
    except FileNotFoundError:
        print("Missing file [clipboard.json]")

    print_dict(data[CLIPBOARD])
    key = input("Key to delete: ")
    try:
        del data[CLIPBOARD][key]
        with open(filepath, 'w') as f:
            json.dump(data, f)
    except KeyError:
        print("Missing key")
    print(f"Key {key} removed")
    return

# Print all items stored in clipboard dict, if cliboard is empty or missing a message is printed.

def list_data(filepath):
    with open(filepath, 'r') as f:
        try:
            data = json.load(f)
            if len(data[CLIPBOARD].keys()) == 0:
                print("Empty clipboard\n")
            else:
                print_dict(data[CLIPBOARD])
        except Exception:
            print("Missing file [clipboard.json]")
    return

# Stores a  key:value pair in clipboard.json

def save(filepath):

    key = input("Enter a key: ")
    newdata = dict()
    newdata[key] = clipboard.paste()

    with open(filepath, 'r') as f:
        data = json.load(f)                    # load data (dict) from file
        f.close()                              # close file, now I can work on data

        data[CLIPBOARD].update(newdata)        # add newdata to dict

    with open(filepath, 'w') as f:
        json.dump(data, f)                     # write updated dict to file

    print(f"{data[CLIPBOARD][key]} saved to key {key}")
    return


def load(filepath):
    try:
        with open(filepath, 'r') as f:
            data = json.load(f)

        if len(data[CLIPBOARD].keys()) == 0:
            print("Empty clipboard")
            return

        print("CLIPBOARD: ")
        print_dict(data[CLIPBOARD])
        keyword = input("Insert key: ")
        try:
            info = data[CLIPBOARD][keyword]
        except KeyError:
            print("Wrong key, retry")
            return

        clipboard.copy(info)
        print("Data in clipboard! Use ctrl+V to paste :)")

    except FileNotFoundError:
        print("Missing file [clipboard.json]")
    return


# Useful instead of switch
command_dict = {
    'save': save,
    'load': load,
    'list': list_data,
    'delete': delete
}

try:
    command = sys.argv[1]
    exec_command = command_dict[command]
except (KeyError, IndexError):
    print("Wrong command! Try multiclipboard.py + : ")
    print_keys(command_dict)
    quit()


# At this point the func is defined. I should just call it

exec_command(SAVED_DATA_PATH)
