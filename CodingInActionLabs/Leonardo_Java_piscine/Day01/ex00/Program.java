
public class Program
{
	public static void main (String[] args)
	{
		User	a = new User(1, "Federico", 1000);
		User	b = new User(2, "Simone", 2000);
		Transaction T = new Transaction(a, b, 500, Transaction.Categories.DEBIT);

		System.out.println("\nBEFORE TRANSACTION\n");
		System.out.println("-UserID: " + a.getID() + "\n	-UserName: " + a.getName() + "	-UserBalance: " + a.getBalance());
		System.out.println("-UserID: " + b.getID() + "\n	-UserName: " + b.getName() + "	-UserBalance: " + b.getBalance());
		System.out.println("\n-TransID: " + T.getID() + "\n	-TransRec: " + T.getRecipient().getName() + "	-TransSend " + T.getSender().getName() + "	-TransAmount " + T.getAmount() + "	-TransCat: " + T.getCategory());

		T.StartTransaction();

		System.out.println("\n\nAFTER TRANSACTION\n");
		System.out.println("-UserID: " + a.getID() + "\n	-UserName: " + a.getName() + "	-UserBalance: " + a.getBalance());
		System.out.println("-UserID: " + b.getID() + "\n	-UserName: " + b.getName() + "	-UserBalance: " + b.getBalance());
		System.out.println("\n-TransID: " + T.getID() + "\n	-TransRec: " + T.getRecipient().getName() + "	-TransSend " + T.getSender().getName() + "	-TransAmount " + T.getAmount() + "	-TransCat: " + T.getCategory());
		System.out.println();
	}
}
