
public class UsersArrayList implements UsersList {

	private User[] listOfUsers;
	private int listSize;
	private static final int DEFAULT_CAPACITY = 10;

	public UsersArrayList()
	{
		listOfUsers = new User[DEFAULT_CAPACITY];
		listSize = 0;
	}

	private void add(User NewUser)
	{
		ensureCapacity();
		listOfUsers[listSize++] = NewUser;
	}

	private void ensureCapacity()
	{
		int listCapacity = listOfUsers.length;

		if(listSize == listCapacity)
		{
			User[] newList = new User[listCapacity + listCapacity/2];
			System.arraycopy(listOfUsers, 0, newList, 0, listCapacity);
			listOfUsers = newList;
		}
	}

	private User get(int index)
	{
		if (index >= listSize)
			throw new UserNotFoundException("There are no users with this index");

		return listOfUsers[index];
	}

	private int size()
	{
		return listSize;
	}

	public void addUser(User NewUser)
	{
		add(NewUser);
	}

	public User searchUserByID(int ID)
	{
		User searchedUser = get(0);

		for (int i = 0; searchedUser.getID() != ID; i++)
			searchedUser = get(i);

		return searchedUser;
	}

	public User searchUserByIndex(int index)
	{
		return get(index);
	}

	public int getNumberOfUsers()
	{
		return size();
	}
}
