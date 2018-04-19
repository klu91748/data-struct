package TreePackage;

import java.util.Iterator;
import java.util.NoSuchElementException;
import StackPackage.*;
import QueuePackage.*;

public class BinaryTree<T> implements BinaryTreeInterface<T>
{
	protected BinaryNode<T> root;
	
	public BinaryTree() 
	{ 
		root = null; 
	}
	public BinaryTree(T rootData) 
	{
		root = new BinaryNode<>(rootData);
	}
	public BinaryTree(T rootData, BinaryTree<T> leftTree, BinaryTree<T> rightTree)
	 {
		 initializeTree(rootData, leftTree, rightTree);
	}
	private void initializeTree(T rootData, BinaryTree<T> leftTree, BinaryTree<T> rightTree)
	{
		root = new BinaryNode<>(rootData);
		
		if((leftTree != null) && !leftTree.isEmpty())
			root.setLeftChild(leftTree.root);
		if((rightTree != null) && !rightTree.isEmpty())
		{
			if (rightTree != leftTree)
				root.setRightChild(rightTree.root);
			else
				root.setRightChild(rightTree.root.copy());
		}
		if((leftTree != null) && (leftTree != this)) 
		{ 
			leftTree.clear(); 
		}
		if((rightTree != null) && (rightTree != this)) 
		{ 
			rightTree.clear(); 
		}
	}

	public T getRootData()
	{
		if(!isEmpty())
		{
			return root.getData();
		}
		return null;

	}
	public int getHeight()
	{
		return root.getHeight();

	}
	public int getNumberOfNodes()
	{
		return root.getNumberOfNodes();
	}
	public boolean isEmpty()
	{
		return root == null;
	}
	public void clear()
	{
		root = null;
	}
	public void setTree(T rootData)
	{
		setTree(rootData, null, null);
	}
	public void setTree(T rootData, BinaryTreeInterface<T> leftTree, BinaryTreeInterface<T> rightTree)
	{
		initializeTree(rootData, (BinaryTree<T>) leftTree, (BinaryTree<T>) rightTree);
	}
	public Iterator<T> getPreorderIterator()
	{
		return null;
	}
	public Iterator<T> getPostorderIterator()
	{
		return new PostOrderIterator();
	}
	public Iterator<T> getInorderIterator()
	{
		return new InOrderIterator();
	}
	public Iterator<T> getLevelOrderIterator()
	{
		return new LevelOrderIterator();
	}
    private class InOrderIterator implements Iterator<T>
    {
        private StackInterface<BinaryNode<T>> nodeStack;
        private BinaryNode<T> currentNode;

        public InOrderIterator()
        {
            nodeStack = new ArrayStack<>();
            currentNode = root;
        }

        @Override
        public boolean hasNext()
        {
            return (!nodeStack.isEmpty()) || (currentNode != null);
        }

        @Override
        public T next()
        {
            BinaryNode<T> nextNode = null;

            // find leftmost node with no left child
            while(currentNode != null)
            {
                nodeStack.push(currentNode);
                currentNode = currentNode.getLeftChild();
            }
            //currentNode turns null
            if(!nodeStack.isEmpty())
            {
                nextNode = nodeStack.pop();
                currentNode = nextNode.getRightChild();
            }
            else
                throw new NoSuchElementException();
            return nextNode.getData();
        }
    }
    private class PostOrderIterator implements Iterator<T>
    {
    	private StackInterface<BinaryNode<T>> nodeStack;
    	private BinaryNode<T> currentNode;
    	
        public PostOrderIterator()
        {
            nodeStack = new ArrayStack<>();
            currentNode = root;
        }
        
    	public boolean hasNext()
    	{
    		return (!nodeStack.isEmpty()) || (currentNode != null);
    	}
    	public T next()
    	{
    		BinaryNode<T> nextNode = null;
    		
    		while(currentNode != null)
    		{
    			nodeStack.push(currentNode);
    			if(currentNode.getLeftChild() == null)
    				currentNode = currentNode.getRightChild();
    			else
    				currentNode = currentNode.getLeftChild();
    		}
    		
    		if(!nodeStack.isEmpty())
    		{
    			nextNode = nodeStack.pop();
    			BinaryNode<T> parent;
    			if(!nodeStack.isEmpty())
    			{
    				parent = nodeStack.peek();
    				if(nextNode == parent.getLeftChild())
    					currentNode = parent.getRightChild();
    				else
    					currentNode = null;
    			}
    			else
    				currentNode = null;
    		}
    		else
    			throw new NoSuchElementException();
    		return nextNode.getData();
    	}
    }
    private class LevelOrderIterator implements Iterator<T>
    {
    	private QueueInterface<BinaryNode<T>> queue;
    	private BinaryNode<T> currentNode;
    	
        public LevelOrderIterator()
        {
            queue = new Queue<>();
            currentNode = root;
            queue.add(currentNode);
        }
        
    	public boolean hasNext()
    	{
    		return (!queue.isEmpty()) || (currentNode != null);
    	}
    	public T next()
    	{
    		BinaryNode<T> nextNode = null;
    		
    		if (hasNext())
    		{
    			nextNode = queue.remove();
    			if (nextNode.getLeftChild() != null)
    				queue.add(nextNode.getLeftChild());
    			if (nextNode.getRightChild() != null)
    				queue.add(nextNode.getRightChild());
    		}
    		else
    			throw new NoSuchElementException();
    		return nextNode.getData();
    	}
    }
}
