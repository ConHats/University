import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		HashMap<String, ArrayList<Book>> library = new HashMap<>();
		
		Book b1 = new Book("Catcher in the Rye");
		Book b2 = new Book("The Alcemist");
		Book b3 = new Book("Giati mas psekazoun");
		Book b4 = new Book("Ti kryboun sto emvolio");
		
		ArrayList<Book> marysBooks = new ArrayList<>();
		marysBooks.add(b1);
		marysBooks.add(b2);
		
		ArrayList<Book> johnsBooks = new ArrayList<>();
		johnsBooks.add(b3);
		johnsBooks.add(b4);
		
		library.put("Mary", marysBooks);
		library.put("John", johnsBooks);
		
		Iterator<String> i = library.keySet().iterator();
		
		while(i.hasNext()) {
			String key = i.next();
			System.out.println(key + " has borrowed the following books");
			ArrayList<Book> borrowedBooks = library.get(key);
			for(Book book: borrowedBooks)
				System.out.println(book.getTitle());
		}
		Stack<String> stack = new Stack<>();
		stack.push("John");
		stack.push("Mary");
		
		System.out.println(stack.pop());
		
	} 
}

class Book{
	
	private String title;
	
	public Book(String title) {
		this.title = title;
	}

	public String getTitle() {
		return title;
	}

	
}