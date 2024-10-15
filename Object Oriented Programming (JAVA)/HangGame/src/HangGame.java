import java.util.Scanner;

public class HangGame {
	private int count;
    private int wins;
    private int losses;

    protected void printMenu() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("MAIN MENU");
            System.out.println("  - Start a new Game (N)");
            System.out.println("  - Statistics (S)");
            System.out.println("  - Exit (E)");
            System.out.print("Please enter your choice: ");

            char choice = scanner.next().toUpperCase().charAt(0);

            switch (choice) {
                case 'N':
                    aGame();
                    break;
                case 'S':
                    displayStatistics();
                    break;
                case 'E':
                    System.out.println("Exiting the game");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private void aGame() {
        count++;

        Dictionary dictionary = new Dictionary();
        Game game = new Game(dictionary.RandomWord());

        while (!game.isFinished()) {
            game.Status();
            char guess = getGuess();
            game.makeGuess(guess);
        }

        game.Result();
        updateStatistics(game);
    }

    private char getGuess() {
        Scanner scanner = new Scanner(System.in);
        char guess;

        while (true) {
            System.out.print("Your guess: ");
            String input = scanner.next().toUpperCase();

            if (input.length() == 1 && Character.isLetter(input.charAt(0))) {
                guess = input.charAt(0);
                break;
            } else {
                System.out.println("Invalid input. Please enter a single letter.");
            }
        }
        scanner.close();
        return guess;
    }

    private void updateStatistics(Game game) {
        if (game.isGameWon()) {
            wins++;
        } else {
            losses++;
        }
    }

    private void displayStatistics() {
        System.out.println("You have played so far " + count + " games. You won " + wins + " times and lost " + losses + " times.");
    }
}

