import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
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

            while (zipEntry != null) {

                boolean isDirectory = false;
                if (zipEntry.getName().endsWith(File.separator)){
                    isDirectory = true;
                }

                String fileName = zipEntry.getName();
                //File newFile = new File(destDir + File.separator + fileName);
                File newFile = protectZipSlip(fileName, destDir);

                if (isDirectory) {
                    // Creating directories
                    System.out.println("Create Directory " + fileName);
                    newFile.mkdirs();
                } else {
                    System.out.println("Unzipping to " + newFile.getAbsolutePath());

                    FileOutputStream fileOutputStream = new FileOutputStream(newFile);

                    int len;
                    while ((len = zipInputStream.read(buffer)) > 0) {
                        fileOutputStream.write(buffer, 0, len);
                    }
                    fileOutputStream.close();
                }

                //close this ZipEntry
                zipInputStream.closeEntry();
                zipEntry = zipInputStream.getNextEntry();
            }

            //close last ZipEntry
            zipInputStream.closeEntry();
            zipInputStream.close();
            fileInputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static File protectZipSlip(String fileName, String destDir) throws IOException{
        Path destPath = Paths.get(destDir);
        Path resolvedDest = destPath.resolve(fileName);
        Path normalizedPath = resolvedDest.normalize();

        // checking whether zipEntry filename has changed the destination
        if (!normalizedPath.startsWith(destDir)) {
            throw new IOException("Malicious zip entry found: " + fileName);
        }

        File newFile = normalizedPath.toFile();
        return newFile;
    }
    public static void main(String[] args) {
        unzip("/home/ayesh/Desktop/example/hello.zip", "/home/ayesh/Desktop/");
    }
}