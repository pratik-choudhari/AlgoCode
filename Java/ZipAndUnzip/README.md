###Description

FileCompressionHandler is a utility class which takes the absolute location of a zip file that should be extracted at the same location or
the absolute location of a folder that should be zipped at the same location.

The program addresses the widely-spread Zip Slip vulnerability while unzipping archives. Zip Slip is a critical vulnerability
that can harmfully create or modify sensitive files outside the working directory.
 
####Example for Zipping a Folder

Input:
```bash
Enter the location of the zipfile or the folder to be zipped:  
/home/person/example
```

####Example for Unzipping a Zip File

Input:
```bash
Enter the location of the zipfile or the folder to be zipped:  
/home/person/example/abc.zip
```

Author: [Ayesh Weerasinghe](https://github.com/AyeshW)