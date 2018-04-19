package coding;
import java.util.*;

public class Main 
{
	public static void main(String[] args)
	{
		Scanner k = new Scanner(System.in);
		GuessingGame game = new GuessingGame("Is it a land animal?","fish","dog");
		String answer = "yes";
		while (answer.equals("yes"))
		{
			game.play();
			System.out.println("Do you want to play again?");
			answer = k.nextLine();
		}

		

	}
}
