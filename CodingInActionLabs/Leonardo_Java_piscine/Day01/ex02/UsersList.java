
public interface UsersList {

	public void addUser(User NewUser);

	public User searchUserByID(int ID);

	public User searchUserByIndex(int index);

	public int getNumberOfUsers();
}
