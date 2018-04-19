package QueuePackage;

public interface QueueInterface<T>
{
	public void add(T newEntry);
	public T remove();
	public boolean isEmpty();
	public void clear();
	public T getBack();
	public T getFront();
}
