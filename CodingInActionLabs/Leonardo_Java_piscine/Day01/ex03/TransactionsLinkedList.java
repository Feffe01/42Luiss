import java.util.UUID;

public class TransactionsLinkedList implements TransactionsList
{
	private Node Head;
	private Node Tail;
	private int size = 0;

	public TransactionsLinkedList()
	{
		Head = null;
		Tail = null;
	}

	private class Node
	{
		Transaction Transaction;
		Node Prev;
		Node Next;

		Node ( Transaction Transaction )
		{
			this.Transaction = Transaction;
			Prev = null;
			Next = null;
		}
	}

	public void add( Transaction NewTrans )
	{
		Node Temp = new Node(NewTrans);
		if (Head == null)
		{
			Head = Temp;
			Tail = Temp;
		}
		else
		{
			Temp.Prev = Tail;
			Tail.Next = Temp;
			Tail = Temp;
		}
		size++;
	};

	public void remove( UUID SearchedID )
	{
		Node Temp = Head;
		
		while ( Temp != null && Temp.Transaction.getID() != SearchedID)
			Temp = Temp.Next;
		
		if ( Temp == null )
			throw new TransactionNotFoundException ("There is no Transaction with this ID");
		else
		{
			if (Temp != Head)
				Temp.Prev.Next = Temp.Next;
			else
				Head = null;
			if (Temp.Next != null)
				Temp.Next.Prev = Temp.Prev;
			size--;
		}
	};

	public Transaction[] toArray()
	{
		Transaction[] TransArray = new Transaction[size];
		Node Temp = Head;

		for (int i = 0; Temp != null; i++)
		{
			TransArray[i] = Temp.Transaction;
			Temp = Temp.Next;
		}

		return TransArray;
	};

}
