import java.util.Scanner;

public class Program
{
	public static void main (String[] args)
	{
		Scanner	scanner = new Scanner(System.in);
		if (!scanner.hasNextInt())
		{
			System.err.println("IllegalArgument");
			System.exit(0);
		}
		int	num = scanner.nextInt();
		scanner.close();

		if (num <= 1)
		{
			System.err.println("IllegalArgument");
			System.exit(0);
		}

		int	count = 0;

		if (num % 2 == 0)
		{
			count++;
			if (num == 2)
			{
				count++;
				System.out.println(true + " " + count);
				System.exit(0);
			}
			System.out.println(false + " " + count);
			System.exit(0);
		}
		count++;

		int i = 3;
		while (num % i != 0 && i < num / 2 + 1)
		{
			count++;
			i += 2;
		}
		count++;

		if (i > num / 2)
			System.out.println(true + " " + count);
		else
			System.out.println(false + " " + count);
	}
}
