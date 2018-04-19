package coding;

import TreePackage.DecisionTreeInterface;

import java.util.Scanner;

import TreePackage.DecisionTree;

public class GuessingGame
{
    private DecisionTreeInterface<String> tree;

    public GuessingGame(String question, String noAnswer, String yesAnswer)
    {	
        DecisionTree<String> no = new DecisionTree<>(noAnswer);
        DecisionTree<String> yes = new DecisionTree<>(yesAnswer);
        tree = new DecisionTree<>(question, no, yes);
    }

    public void play()
    {
    	Scanner k = new Scanner(System.in);
    	while (!tree.isAnswer())
    	{
    		System.out.println(tree.getCurrentData());
    		String answer = k.nextLine();
    		
    		if (answer.equals("no"))
    		{
    			tree.advanceToNo();
    			if (tree.isAnswer())
    			{
    				System.out.println("I guess "+tree.getCurrentData()+".");
    				answer = k.nextLine();
    				
    				if (answer.equals("yes"))
    					System.out.println("I win");
    				if (answer.equals("no"))
    					learn();
    				tree.resetCurrentNode();
    				break;
    			}
    		}
    		if (answer.equals("yes"))
    		{
    			tree.advanceToYes();
    			if (tree.isAnswer())
    			{
    				System.out.println("I guess "+tree.getCurrentData()+".");
    				answer = k.nextLine();
    				
    				if (answer.equals("yes"))   				
    					System.out.println("I win");   					   				
    				if (answer.equals("no"))
    					learn();
    				tree.resetCurrentNode();
    				break;
    			}
    		}
    		
    	}
    }

    public void learn()
    {
    	Scanner k = new Scanner(System.in);
    	
    	System.out.println("What animal was it?");
    	String animal = k.nextLine();
    	System.out.println("Give me a question whose answer is yes and no.");
    	String question = k.nextLine();
    	
    	String temp = tree.getCurrentData();
    	tree.setCurrentData(question);
    	tree.setResponses(temp, animal);

    }
}
