import java.util.Random;

public class Dictionary {
	public String getWord(int index) {
        switch (index) {
            case 0: return "UNIVERSITY";
            case 1: return "COMPUTER";
            case 2: return "LAPTOP";
            case 3: return "HEADPHONES";
            case 4: return "FUZZY";
            case 5: return "DOG";
            case 6: return "KEYHOLE";
            case 7: return "TELEPHONE";
            case 8: return "PRINTER";
            case 9: return "BUILDING";
            default: return "Illegal index";
        }
    }

    public String RandomWord() {
        int randomIndex = new Random().nextInt(10); // Assuming you have 10 words
        return getWord(randomIndex);
    }
}
