
public class Game {
	private String secretWord;
    private StringBuilder guessedWord;
    private int remainingGuesses;

    public Game(String secretWord) {
        this.secretWord = secretWord;
        this.guessedWord = new StringBuilder("-".repeat(secretWord.length()));
        this.remainingGuesses = 8;
    }

    public boolean isFinished() {
        return remainingGuesses <= 0 || guessedWord.toString().equals(secretWord);
    }

    public void Status() {
        System.out.println("The random word is now: " + guessedWord);
        System.out.println("You have " + remainingGuesses + " guesses left.");
    }

    public void makeGuess(char guess) {
        if (secretWord.contains(String.valueOf(guess))) {
            System.out.println("The guess is CORRECT!");
            for (int i = 0; i < secretWord.length(); i++) {
                if (secretWord.charAt(i) == guess && guessedWord.charAt(i) != guess) {
                    guessedWord.setCharAt(i, guess);
                }
            }
        } else {
            System.out.println("There are no " + guess + "'s in the word.");
            remainingGuesses--;
        }
    }

    public boolean isGameWon() {
        return guessedWord.toString().equals(secretWord);
    }

    public void Result() {
        if (isGameWon()) {
            System.out.println("Congratulations! You guessed the word: " + secretWord);
        } else {
            System.out.println("Sorry, you ran out of guesses. The word was: " + secretWord);
        }
        System.out.println("You made " + getCorrectGuesses() + " correct guesses and " + (8 - remainingGuesses) + " wrong guesses.");
    }

    private int getCorrectGuesses() {
        int correctGuesses = 0;
        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord.charAt(i) == guessedWord.charAt(i)) {
                correctGuesses++;
            }
        }
        return correctGuesses;
    }
}
    