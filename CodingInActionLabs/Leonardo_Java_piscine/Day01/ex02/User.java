
public class User
{
	private int ID;
	private String Name;
	private int Balance;

	public User(String NameSet, int BalanceSet)
	{
		this.ID = UserIdsGenerator.getInstance().generateId();
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
