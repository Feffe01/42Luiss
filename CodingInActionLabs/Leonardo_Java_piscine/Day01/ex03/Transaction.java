
import java.util.UUID;

public class Transaction
{
	public enum Categories{DEBIT, CREDIT};

	private UUID ID;
	private User Recipient;
	private User Sender;
	private int TransAmount;
	private Categories Category;

	public Transaction(User RecipientSet, User SenderSet, int TransAmountSet, Categories CategorySet)
	{
		this.ID = UUID.randomUUID();
		this.Recipient = RecipientSet;
		this.Sender = SenderSet;
		this.TransAmount = TransAmountSet;
		this.Category = CategorySet;
	}

	public void StartTransaction()
	{
		Recipient.transanction(TransAmount);
		Recipient.TransList.add(this);
		Sender.transanction(-TransAmount);
		Sender.TransList.add(this);
	}

	public UUID getID()
	{
		return ID;
	}

	public User getRecipient()
	{
		return Recipient;
	}

	public User getSender()
	{
		return Sender;
	}

	public int getAmount()
	{
		return TransAmount;
	}

	public Categories getCategory()
	{
		return Category;
	}
}
