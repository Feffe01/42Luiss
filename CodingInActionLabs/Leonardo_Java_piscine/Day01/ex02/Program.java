
public class Program
{
	public static void main (String[] args)
	{
		UsersArrayList lista = new UsersArrayList();

		System.out.println("\nCREATING USER LIST AND SHOWING IT BY SEARCHING BY INDEXES\n");
		for (int i = 0; i < 100; i++)
		{
			User x = new User("User", 1000);

			lista.addUser(x);

			System.out.println((lista.searchUserByIndex(i)).getName() + (lista.searchUserByIndex(i)).getID());
		}

		System.out.println("\nNUMBER OF USERS IN THE LIST\n");
		System.out.println("	" + lista.getNumberOfUsers());

		System.out.println("\nSEARCHING USER BY INDEX 42\n");
		System.out.println("	" + (lista.searchUserByIndex(42)).getName() + (lista.searchUserByIndex(42)).getID());

		System.out.println("\nSEARCHING USER BY ID 84\n");
		System.out.println("	" + (lista.searchUserByID(84)).getName() + (lista.searchUserByID(84)).getID());

		System.out.println("\nSEARCHING USER BY ID 4242 (exception)\n");
		System.out.println("	" + (lista.searchUserByID(4242)).getName() + (lista.searchUserByID(4242)).getID());

		System.out.println();
	}
}
