#include "TList.hpp"

size_t mygetch()
{
	size_t key;
	do
	{
		key = _getch() - 48;
	} while (!(key >= 0 && key <= 6));
	return key;
}

int main()
{
	TList<int> mas;
	cout
		<< "mas\n->";
	cin >> mas;
	int key = 0;

	while (1)
	{
		switch (key)
		{
		case 0:
		{
			cout << "\n\n\n0.Exit to menu"
				 << "\n1.Insertion"
				 << "\n2.Removal"
				 << "\n3.Replacement"
				 << "\n4.Search sublist"
				 << "\n5.Union"
				 << "\n6.Intersection"
				 << "\nEnter key";
			key = mygetch();
			cout << "\n\n";
			break;
		}
		case 1:
		{
			TList<int> insertionList;
			cout << "InsertList\n->";
			cin >> insertionList;

			mas.Insert(insertionList.begin(), insertionList.end(), 0);
			cout << "Result:\n"
				 << mas << '\n';
			key = 0;
			break;
		}
		case 2:
		{
			cout << "Enter begin and end positions for removal\n";
			cout << " Possible options: ";
			int beginPos = 1, endPos;
			for (auto &c : mas)
			{
				cout << beginPos++ << " ";
			}
			cout << '\n';
			cin >> beginPos >> endPos;
			auto iterBegin = mas.begin();
			for (int i = 1; i < beginPos; ++i)
			{
				++iterBegin;
			}
			auto iterEnd = iterBegin;
			for (int i = beginPos; i <= endPos; ++i)
			{
				++iterEnd;
			}
			mas.Delete(iterBegin, iterEnd);
			cout << "Result:\n";
			cout << mas;
			cout << '\n';
			key = 0;
			break;
		}
		case 3:
		{
			cout << "Enter begin and end positions for replacement\n";
			cout << " Possible options: ";
			int beginPos = 1, endPos;
			for (auto &c : mas)
			{
				cout << beginPos++ << " ";
			}
			cout << '\n';
			cin >> beginPos >> endPos;
			auto iterBegin = mas.begin();
			for (int i = 1; i < beginPos; ++i)
			{
				++iterBegin;
			}
			auto iterEnd = iterBegin;
			for (int i = beginPos; i <= endPos; ++i)
			{
				++iterEnd;
			}

			TList<int> insertionList;
			cout << "entering mas for replacement\n";
			cin >> insertionList;

			mas.Replace(iterBegin, iterEnd, insertionList.begin(), insertionList.end());
			cout << "Result:\n";
			cout << mas;
			cout << '\n';

			key = 0;
			break;
		}
		case 4:
		{
			TList<int> searchList;
			cout << "entering search mas\n";
			cin >> searchList;
			auto searchResult = mas.Search(searchList);
			if (searchResult == mas.end())
			{
				cout << "Not found!\n";
			}
			else
			{
				cout << "Found! ";
				auto iterBegin = mas.begin();
				int i = 1;
				while (iterBegin != searchResult)
				{
					++i;
					++iterBegin;
				}
				cout << " position = " << i << '\n';
			}
			key = 0;
			break;
		}

		case 5:
		{
			TList<int> unionList;
			cout << "entering union mas\n";
			cin >> unionList;
			TList<int> result = mas.Union(unionList);
			cout << "Result:\n";
			cout << result;
			cout << '\n';
			key = 0;
			break;
		}

		case 6:
		{
			TList<int> intersectionList;
			cout << "entering intersection mas\n";
			cin >> intersectionList;
			TList<int> result = mas.Intersection(intersectionList);
			cout << "Result:\n";
			cout << result;
			cout << '\n';
			key = 0;
			break;
		}
		}
	}

	system("pause");
}
