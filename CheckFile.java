import java.io.File;

public class CheckFile {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Будь ласка, вкажіть шлях до файлу.");
            return;
        }

        String filePath = args[0];
        File file = new File(filePath);

        if (file.exists() && file.isFile()) {
            System.out.println("Файл існує: " + filePath);
        } else {
            System.out.println("Файл не знайдено: " + filePath);
        }
    }
}