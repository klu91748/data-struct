package QueuePackage;

public class Queue<T> implements QueueInterface<T>
{
	private Node firstNode = null;
	private Node lastNode = null;
	
	private class Node
	{
		private T data;
		private Node next;
		
		private Node (T d)
		{
			data = d;
			next = null;
		}
		public void setNextNode(Node n)
		{
			next = n;
		}

		public T getData()
		{
			return data;
		}
		
		public void setData(T d)
		{
			data = d;
		}
	}
	
	@Override
	public void add(T newEntry)
	{
		Node newNode = new Node(newEntry);
		if (isEmpty())
		{
			firstNode = newNode;
			lastNode = firstNode;
		}
		else
		{
			lastNode.setNextNode(newNode);
			lastNode = newNode;
		}
	}
	
	@Override	
	public T remove()
	{
		if (firstNode == null)
		{
			lastNode = null;
			return null;
		}
		
		Node removedNode = firstNode;
		firstNode = firstNode.next;

		return removedNode.data;
	}
	
	@Override	
	public boolean isEmpty()
	{
		boolean flag = false;
		if (firstNode == null && lastNode == null)
			flag = true;
		return flag;
	}
	
	@Override	
	public void clear()
	{
		firstNode = null;
		lastNode = null;
	}
	
	@Override	
	public T getBack()
	{
		return lastNode.getData();
	}
	
	@Override	
	public T getFront()
	{
		
		return firstNode.getData();
	}
	
    public String toString()
    {
        StringBuilder returnString = new StringBuilder();
        for(Node n = firstNode; n != null; n = n.next)
        {
            returnString.append(n.data + " \n");
        }
        return returnString.toString();
    }
}

