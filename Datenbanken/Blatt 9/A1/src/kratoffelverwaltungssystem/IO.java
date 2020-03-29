package kratoffelverwaltungssystem;

import java.io.IOException;

public class IO {

    public static final String WELCOMESTRING = "Willkommen beim Kartoffelverwaltungssystem 36187!";
    public static final String USERNAMESTRING = "Bitte Geben Sie Ihren Nutzernamen ein:";
    public static final String PASSWORDSTRING = "Bitte Geben Sie Ihr Passwort ein:";


    public static String readLine(String s) {
        System.out.print(s);
        String str = "";
        try {
            int i;
            while ((i = System.in.read()) != 10) {
                str += (char) i;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    public static void printWelcome() {
        System.out.println(WELCOMESTRING);
    }

    public static String getUserName() {
        return readLine(USERNAMESTRING);
    }

    public static String getPassword() {
        return readLine(PASSWORDSTRING);
    }

    public static int selectFromList(String[] list) {
        for (int i = 0; i < list.length; i++) {
            System.out.printf("%d) %s\n", i + 1, list[i]);
        }
        int selection;
        while (true) {
            try {
                selection = Integer.valueOf(readLine(""));
                if (selection > 0 && selection <= list.length) {
                    break;
                }
            } catch (NumberFormatException e) {
                System.out.printf("Invalid Selection!");
            }
        }
        return selection - 1;
    }

    public static Command selectCommand() {
        for (int i = 0; i < Command.values().length; i++) {
            System.out.printf("%d) %s\n", i + 1, Command.values()[i].description);
        }
        int selection;
        while (true) {
            try {
                selection = Integer.parseInt(readLine(""));
                if (selection > 0 && selection <= Command.values().length) {
                    break;
                }
            } catch (NumberFormatException e) {
                System.out.print("Invalid Selection!\n");
            }
        }
        return Command.values()[selection - 1];
    }

    public static OrtT selectOrtT() {
        System.out.println("Ortstyp auswählen!");
        for (int i = 0; i < OrtT.values().length; i++) {
            System.out.printf("%d) %s\n", i + 1, OrtT.values()[i].name);
        }
        int selection;
        while (true) {
            try {
                selection = Integer.parseInt(readLine(""));
                if (selection > 0 && selection <= OrtT.values().length) {
                    break;
                }
            } catch (NumberFormatException e) {
                System.out.print("Invalid Selection!\n");
            }
        }
        return OrtT.values()[selection - 1];
    }

    public static int getID() {
        return 0;
    }

    public static String getSorte() {
        return "";
    }

    public static Float getSize() {
        return 0f;
    }

    public static Float getWeight() {
        return 0f;
    }

    public static float getStarch() {
        return 0f;
    }

    public static float getSpottiness() {
        return 0f;
    }

    public static int getOrtID() {
        return 0;
    }
}
