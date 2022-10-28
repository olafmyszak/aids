#include <iostream>
#include <utility>

using namespace std;

class Mountain
{
 private:
  string name;
  unsigned long height;

 public:
  Mountain()
  {
	this->name = " ";
	this->height = 0;
  }

  Mountain(string name, unsigned long height)
  {
	this->name = std::move(name);
	this->height = height;
  }

  void setName(string name)
  {
	this->name = std::move(name);
  }

  void setHeight(unsigned long height)
  {
	this->height = height;
  }

  unsigned long getHeight() const
  {
	return height;
  }

  string getName() const
  {
	return name;
  }

  bool isPowerOfTwo() const
  {
	return !(height & (height-1));
  }
};

void printArray(Mountain mountain[], int n)
{
  for (int i = 0; i < n; ++i)
  {
	printf("%s-%lu ", mountain[i].getName().c_str(), mountain[i].getHeight());
  }
}

void sortByPower(Mountain mountains[], int n)
{
  Mountain key;
  int j;

  for(int i=1; i<n; ++i)
  {
	key = Mountain(mountains[i].getName(), mountains[i].getHeight());
	j=i;

	while (j>0 && (!mountains[j-1].isPowerOfTwo() && key.isPowerOfTwo()))
	{
	  mountains[j].setHeight(mountains[j-1].getHeight());
	  mountains[j].setName(mountains[j-1].getName());
	  --j;
	}

	mountains[j].setHeight(key.getHeight());
	mountains[j].setName(key.getName());
  }
}

void sortAscend(Mountain mountains[], int n)
{
  Mountain key;
  int j;

  for (int i = 1; i < n; ++i)
  {
	key = Mountain(mountains[i].getName(), mountains[i].getHeight());

	j = i ;

	while (j > 0 && mountains[j-1].getHeight() > key.getHeight())
	{
	  mountains[j].setHeight(mountains[j-1].getHeight());
	  mountains[j].setName(mountains[j-1].getName());
	  --j;
	}

	mountains[j].setHeight(key.getHeight());
	mountains[j].setName(key.getName());
  }
}

int main()
{
  short t;
  int n;
  unsigned long w;
  string s;

  scanf("%hd", &t);

  for (short i = 0; i < t; ++i)
  {
	scanf("%d", &n);

	Mountain *mountains = new Mountain[n];

	for (int j = 0; j < n; ++j)
	{
	  char tmp[10000];
	  scanf("%s %ld", tmp, &w);
	  s = tmp;
	  mountains[j] = Mountain(s, w);

	}
	sortAscend(mountains, n);
	sortByPower(mountains, n);
	printArray(mountains, n);

	delete[] mountains;
  }
  return 0;
}