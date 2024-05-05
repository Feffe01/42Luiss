
public class User
{
	private int ID;
	private String Name;
	private int Balance;

	public User(int IDset, String NameSet, int BalanceSet)
	{
		this.ID = IDset;
		this.Name = NameSet;
		this.Balance = BalanceSet;
	}

	public void transanction(int Amount)
	{
		Balance += Amount;
	}

	public int getID()
	{
		return ID;
	}

	public String getName()
	{
		return Name;
	}

	public int getBalance()
	{
		return Balance;
	}
}
