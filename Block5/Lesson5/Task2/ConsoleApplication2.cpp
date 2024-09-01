#include <iostream>

template<class T>
class Table {
public:
	Table(int rows, int cols) : _rows(rows), _cols(cols) {
		_arr = new T * [_rows] {};

		for (int i{}; i < _rows; ++i) {
			_arr[i] = new T[_cols]{};
		}
	};
	Table(const Table& other) {
		this->_rows = other._rows;
		this->_cols - other._cols;
		_arr = new T * [other._rows] {};

		for (int i{}; i < other._rows; ++i) {
			_arr = new T[other._cols]{};
		}

		for (int i{}; i < other._rows; ++i) {
			for (int j{}; j < other._cols; ++j) {
				_arr[i][j] = other._arr[i][j];
			}
		}
	}

	Table& operator=(const Table&) = delete;

	~Table() {
		for (int i{}; i < _rows; ++i) {
			delete[] _arr[i];
		}
		delete[] _arr;
	}

	T* operator[] (int index)
	{
		if (index >= _rows || index < 0)
		{
			throw std::out_of_range("Индекс массива находится вне диапазона");
		}
		return _arr[index];
	}
	T* operator[] (int index) const
	{
		if (index >= _rows || index < 0) throw std::out_of_range("Индекс массива находится вне диапазона");
		return _arr[index];
	}
	void get_size() const
	{
		std::cout << "Массив состоит из " << _rows << " строк и  " << _cols << " столбцов\n";
	}
private:
	int _rows;
	int _cols;
	T** _arr;
};
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	const int ROWS = 5;
	const int COLS = 5;

	Table<int> table{ ROWS, COLS };
	table.get_size();
	try
	{
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLS; ++j)
			{
				table[i][j] = (i + 1) * (j + 1);
				std::cout << table[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}
	catch (std::out_of_range& err)
	{
		std::cout << "Ошибка! " << err.what() << std::endl;
	}
	return 0;
}