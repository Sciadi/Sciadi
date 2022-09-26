
from genericpath import exists
import os
import time

from pathlib import Path
from watchdog.events import FileSystemEventHandler
from watchdog.observers import Observer

DOWNLOAD_PATH = (str(Path.home()) + os.sep + 'Downloads')
NEW_DOWNLOAD_PATH = (str(Path.home()) + os.sep + 'MyDownloads')


def on_created(event):
    filepath = event.src_path
    if os.path.isdir(filepath):
        return
    else:
        filename = os.path.basename(filepath)
        dot_idx = filename.rfind('.') + 1
        new_file_or_dir_path = NEW_DOWNLOAD_PATH + os.sep + filename[dot_idx:]

    if not exists(new_file_or_dir_path):
        os.mkdir(new_file_or_dir_path)
        print(f"creata cartella {new_file_or_dir_path}")

    os.rename(filepath, new_file_or_dir_path + os.sep + filename)
    print(f"Spostato {filepath} in  {new_file_or_dir_path}\n")
    return


if not exists(NEW_DOWNLOAD_PATH):
    os.mkdir(NEW_DOWNLOAD_PATH)
event_handler = FileSystemEventHandler()

event_handler.on_created = on_created

observer = Observer()
observer.schedule(event_handler, DOWNLOAD_PATH, recursive=False)
observer.start()

try:
    while True:
        time.sleep(10)
except KeyboardInterrupt:
    observer.stop()
    observer.join()
