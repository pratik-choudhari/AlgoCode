import os

DOC_EXTENSIONS = [
    ".doc",
    ".docx",
    ".pdf",
    ".rtf",
    ".tex",
    ".txt",
    ".wpd"
]

MULTIMEDIA_EXTENSIONS = [
    ".3g2",
    ".3gp",
    ".avi",
    ".flv",
    ".h264",
    ".m4v",
    ".mkv",
    ".mov",
    ".mp4",
    ".mpg",
    ".mpeg",
    ".rm", 
    ".swf",
    ".vob",
    ".wmv",
    ".aif",
    ".cda",
    ".mid",
    ".mp3",
    ".mpa",
    ".ogg",
    ".wav",
    ".wma",
    ".wpl",
]

SYSTEM_EXTENSIONS = [
    ".bak",
    ".cab",
    ".cfg",
    ".cpl",
    ".cur",
    ".dll",
    ".dmp",
    ".drv",
    ".icn",
    ".ico",
    ".ini",
    ".lnk",
    ".msi",
    ".sys",
    ".tmp",
    
]

IMAGE_EXTENSIONS = [
    ".ai",
    ".bmp",
    ".gif",
    ".ico",
    ".jpeg",
    ".jpg",
    ".png",
    ".ps",
    ".psd",
    ".svg",
    ".tif", 
    ".tiff "
]

EXECUTABLE_EXTENSIONS = [
    ".apk",
    ".bat",
    ".bin",
    ".cgi",
    ".com ",
    ".exe",
    ".jar",
    ".msi",
    ".wsf",
    ".gadget"
]

#Creates de dir if it doesn't exist and returns its path
def createDir(path, name, fileName, fileExtension):
    pathName = os.path.join(path,name)
    if not os.path.isdir(pathName):
        os.mkdir(pathName)
    destinationPath = os.path.join(path, name, fileName + fileExtension) 
    return destinationPath

def main():
    #Get actual relative path
    path = os.getcwd()

    #Get all files in folder
    filesInFolder = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
    for file in filesInFolder:
        fileName, fileExtension = os.path.splitext(file)
        sourceFile = os.path.join(path, fileName + fileExtension)
        destPath = sourceFile
        
        #Check extension and create its folder if it does not exist
        if fileExtension in DOC_EXTENSIONS:
            destPath = createDir(path,"Documents",fileName,fileExtension)
            
        elif fileExtension in MULTIMEDIA_EXTENSIONS:
            destPath = createDir(path,"Multimedia",fileName,fileExtension)
            
        elif fileExtension in SYSTEM_EXTENSIONS:
            destPath = createDir(path,"System",fileName,fileExtension)
           
        elif fileExtension in EXECUTABLE_EXTENSIONS:
            destPath = createDir(path,"Executables",fileName,fileExtension)
           
        elif fileExtension in IMAGE_EXTENSIONS:
            destPath = createDir(path,"Images",fileName,fileExtension)
        
        else:
            continue

        #Move the file to its corresponding folder
        os.rename(sourceFile, destPath)


if __name__ == "__main__":
    main()