
import java.util.UUID;

public interface TransactionsList {

	public void add( Transaction newTrans);

	public void remove( UUID index );

	public Transaction[] toArray();

}
