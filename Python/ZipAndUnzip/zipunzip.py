# importing required modules 
from zipfile import ZipFile 
import os 
import sys
  
def getAllFilePaths(directory):   
    # initializing empty file paths list 
    filePaths = [] 
  
    # crawling through directory and subdirectories 
    for root, directories, files in os.walk(directory): 
        for filename in files: 
            # join the two strings in order to form the full filepath. 
            filepath = os.path.join(root, filename) 
            filePaths.append(filepath) 
  
    # returning all file paths 
    return filePaths         
  
def zip(directories, zippedFileName):   
    # calling function to get all file paths in the directories
    filePaths = []
    for directory in directories:
        filePaths += getAllFilePaths(directory) 

    # check if atleast one folder name is provided
    if len(filePaths) == 0:
        print("0 folders provided. Try providing folders instead of files.")
        sys.exit(1)
  
    # printing the list of all files to be zipped 
    print('Files to be zipped:') 
    for fileName in filePaths: 
        print(fileName) 
  
    # writing files to a zipfile 
    with ZipFile(zippedFileName,'w') as zip: 
        # writing each file one by one 
        for file in filePaths: 
            zip.write(file) 
  
    print('All files zipped successfully!')         


def unzip(zippedFolder):
    with ZipFile(zippedFolder, 'r') as zip: 
        # printing all the contents of the zip file 
        zip.printdir() 
    
        # extracting all the files 
        print('Extracting all the files now...') 
        zip.extractall() 
        print('Done!') 

def main():
    args = sys.argv
    numberOfArgs = len(sys.argv)
    action = args[1]
    print("Action:", action)
    if action == "zip":
        if numberOfArgs <= 3:
            print("Invalid arguments")
            sys.exit(1)
        zippedFileName = args[2]
        directoriesToBeZipped = args[3:]
        zip(directoriesToBeZipped, zippedFileName)
    if action == "unzip":
        if numberOfArgs != 3:
            print("Invalid arguments")
            sys.exit(1)
        zippedFolder = args[2]
        try:
            unzip(zippedFolder)
        except FileNotFoundError as e:
            print(f"Zipped folder {zippedFolder} not found.")
            sys.exit(1)
        except PermissionError as e:
            print(f"{e}. Try removing read-only permissions from this file.")

if __name__ == "__main__": 
    main() 
