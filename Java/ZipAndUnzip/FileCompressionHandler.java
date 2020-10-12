import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class FileCompressionHandler {

    public void zip(String folderPath) {

    }

    public static void unzip(String zipFilePath, String destDir) {
        File dir = new File(destDir);
        // create output directory if it doesn't exist
        if (!dir.exists()) {
            dir.mkdirs();
        }
        FileInputStream fileInputStream;
        //buffer for read and write data to file
        byte[] buffer = new byte[1024];
        try {
            fileInputStream = new FileInputStream(zipFilePath);
            ZipInputStream zipInputStream = new ZipInputStream(fileInputStream);
            ZipEntry zipEntry = zipInputStream.getNextEntry();

            if (zipEntry != null) {
                while (zipEntry != null) {
                    String fileName = zipEntry.getName();
                    File newFile = new File(destDir + File.separator + fileName);
                    System.out.println("Unzipping to " + newFile.getAbsolutePath());

                    //create directories for sub directories in zip
                    File parent = new File(newFile.getParent());
                    parent.mkdir();
                    FileOutputStream fileOutputStream = new FileOutputStream(newFile);

                    int len;
                    while ((len = zipInputStream.read(buffer)) > 0) {
                        fileOutputStream.write(buffer, 0, len);
                    }
                    fileOutputStream.close();
                    //close this ZipEntry
                    zipInputStream.closeEntry();
                    zipEntry = zipInputStream.getNextEntry();
                }
            } else {
                System.out.print("Empty Zip file received.");
            }

            //close last ZipEntry
            zipInputStream.closeEntry();
            zipInputStream.close();
            fileInputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        unzip("/home/ayesh/Desktop/example/lab3_160453M_160671L.zip", "/home/ayesh/Desktop/example/");
    }
}