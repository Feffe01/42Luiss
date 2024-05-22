
import java.util.UUID;

public class Program
{
	public static void main (String[] args)
	{
		System.out.println("\n\n		USERS\n");

		User Federico = new User("Federico", 1000);
		User Sara = new User("Sara", 1000);
		User Giulio = new User("Giulio", 1000);

		System.out.println(Federico.getID() + " - " + Federico.getName() + ": " + Federico.getBalance());
		System.out.println(Sara.getID() + " - " + Sara.getName() + ": " + Sara.getBalance());
		System.out.println(Giulio.getID() + " - " + Giulio.getName() + ": " + Giulio.getBalance());


		System.out.println("\n\n		STARTING AND SAVING TRANSACTIONS\n");

		Transaction A = new Transaction(Federico, Giulio, 200, Transaction.Categories.CREDIT);
		Transaction B = new Transaction(Sara, Giulio, 200, Transaction.Categories.CREDIT);
		Transaction C = new Transaction(Giulio, Federico, 100, Transaction.Categories.DEBIT);
		Transaction D = new Transaction(Giulio, Sara, 200, Transaction.Categories.DEBIT);

		Transaction[] All = {A, B, C, D};

		TransactionsLinkedList WholeTransList = new TransactionsLinkedList();

		for (int i = 0; i < All.length; i++)
		{
			All[i].StartTransaction();
			WholeTransList.add(All[i]);
			System.err.println("Transaction " + i + ": " + All[i].getSender().getName() + " -> " + All[i].getRecipient().getName() + "	" + All[i].getAmount());
		}


		System.out.println("\n\n		CREATED ARRAYS");

		Transaction[] AllCreated = WholeTransList.toArray();
		Transaction[] AllFederico = Federico.TransList.toArray();
		Transaction[] AllSara = Sara.TransList.toArray();
		Transaction[] AllGiulio = Giulio.TransList.toArray();

		System.out.println("\nWhole Transaction list:");
		for (int i = 0; i < AllCreated.length; i++)
			System.err.println("	Transaction " + i + ": " + AllCreated[i].getSender().getName() + " -> " + AllCreated[i].getRecipient().getName() + "	" + AllCreated[i].getAmount());

		System.out.println("\nFederico Transaction list:");
		for (int i = 0; i < AllFederico.length; i++)
			System.err.println("	Transaction " + i + ": " + AllFederico[i].getSender().getName() + " -> " + AllFederico[i].getRecipient().getName() + "	" + AllFederico[i].getAmount());

		System.out.println("\nSara Transaction list:");
		for (int i = 0; i < AllSara.length; i++)
			System.err.println("	Transaction " + i + ": " + AllSara[i].getSender().getName() + " -> " + AllSara[i].getRecipient().getName() + "	" + AllSara[i].getAmount());

		System.out.println("\nGiulio Transaction list:");
		for (int i = 0; i < AllGiulio.length; i++)
			System.err.println("	Transaction " + i + ": " + AllGiulio[i].getSender().getName() + " -> " + AllGiulio[i].getRecipient().getName() + "	" + AllGiulio[i].getAmount());

		
		System.out.println("\n\n		REMOVING THE SARA -> GIULIO TRANSACTION BY UUID\n");

		WholeTransList.remove(D.getID());
		Transaction[] Temp = WholeTransList.toArray();
		for (int i = 0; i < Temp.length; i++)
			System.err.println("	Transaction " + i + ": " + Temp[i].getSender().getName() + " -> " + Temp[i].getRecipient().getName() + "	" + Temp[i].getAmount());

		System.out.println("\n\n		REMOVING AN UUID THAT DOESN'T EXIST (unless the randomUUID function casually gets one that does exist)\n");

		UUID x = UUID.randomUUID();
		WholeTransList.remove(x);
		Transaction[] TempTwo = WholeTransList.toArray();
		for (int i = 0; i < TempTwo.length; i++)
			System.err.println("	Transaction " + i + ": " + TempTwo[i].getSender().getName() + " -> " + TempTwo[i].getRecipient().getName() + "	" + TempTwo[i].getAmount());
		
		System.out.println();
	}
}
