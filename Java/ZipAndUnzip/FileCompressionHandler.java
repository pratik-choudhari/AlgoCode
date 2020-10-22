import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Properties;
import java.util.Scanner;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;
import java.util.zip.ZipOutputStream;

public class FileCompressionHandler {
    // ----------------------------------- zipping ---------------------------------------
    public static void zipFolder(String folderPath) {
        // identify the output directory
        try {
            File inputFolder = new File(folderPath);
            String outputFile = inputFolder.getAbsolutePath() + ".zip";
            System.out.println("Started zipping to " + outputFile);

            FileOutputStream fileOutputStream = new FileOutputStream(outputFile);
            ZipOutputStream zipOutputStream = new ZipOutputStream(fileOutputStream);

            recursiveZip(inputFolder, inputFolder.getName(), zipOutputStream);
            zipOutputStream.close();
            fileOutputStream.close();

        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Zipping Completed Successfully");

    }

    public static void recursiveZip(File inputFile, String fileName, ZipOutputStream zout) throws IOException{
        if (inputFile.isHidden()) {
            return;
        }

        if (inputFile.isDirectory()) {
            ZipEntry zipEntry = null;
            if (fileName.endsWith("/")) {
                zipEntry = new ZipEntry(fileName);
            } else {
                zipEntry = new ZipEntry(fileName + "/");
            }

            zout.putNextEntry(zipEntry);
            zout.closeEntry();

            File[] childFiles = inputFile.listFiles();
            for (File childFile: childFiles) {
                recursiveZip(childFile, fileName + "/" + childFile.getName(), zout);
            }

            return;
        }

        // handling termination condition for non-directory single file
        ZipEntry zipEntry = new ZipEntry(fileName);
        zout.putNextEntry(zipEntry);
        FileInputStream fileInputStream = new FileInputStream(inputFile);

        byte[] buffer = new byte[1024];
        int len;
        while ((len = fileInputStream.read(buffer)) >= 0) {
            zout.write(buffer, 0, len);
        }
        fileInputStream.close();
        zout.closeEntry();
    }

    // ------------------------------- unzipping ------------------------------------
    public static void unzipFile(String zipFilePath) {
        // identify the output directory
        File inputFile = new File(zipFilePath);
        String destDir = inputFile.getParent();
        File dir = new File(destDir);

        // create output directory if it doesn't exist
        if (!dir.exists()) {
            dir.mkdirs();
        }
        FileInputStream fileInputStream;

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

                    //buffer for read and write data to file
                    byte[] buffer = new byte[1024];
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

        System.out.println("Unzipping Completed Successfully");
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

        // the location should be the absolute path to the zipfile or to the folder to be zipped
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the location of the zipfile or the folder to be zipped: ");
        String source = scanner.nextLine();

        if (source.endsWith(".zip")) {
            unzipFile(source);
        } else {
            zipFolder(source);
        }
    }
}