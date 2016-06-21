/**
 * @file BitArray.cc
 * @Brief  Bit array implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-06-17
 */

class BitArray
{
    public:
	BitArray(int size, bool value = false);
	~BitArray();

	bool set(int position, bool value);
	bool fill(int from, int to, bool value);
	bool setAll(bool value);
	bool clear();

    private:
	char *start;
	int end;
};
