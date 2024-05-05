
public class Program
{
	public static void main (String[] args)
	{
		System.out.println("\nUSERS\n");

		for (int i = 1; i <= 100; i++)
		{
			User x = new User("User", 1000);

			System.out.println(x.getName() + i + ": " + x.getID());
		}

		System.out.println();
	}
}
