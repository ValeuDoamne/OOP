#pragma once

template<typename K, typename V>
struct Pereche {
    K key;
    V value;
    int index;
};

template<typename K, typename V>
class Map {
	Pereche<K, V> v[100];
	int count;
public:
	Map(): count(0) { }
	V& operator[](K key) {
		for (int i = 0; i < count; ++i) {
		    if (v[i].key == key) {
			return v[i].value;
		    }
		}
		v[count].key = key;
		v[count].index = count++;
		return v[count-1].value;
	}

	void Print();

	class iterator {
		Pereche<K, V>* ptr;
		public:
		iterator(const Pereche<K,V>* p) {ptr = (Pereche<K, V>*)p;}
		iterator operator++() { ptr += sizeof(Pereche<K, V>); return *this; }
		bool operator!=(const iterator & other) const { return ptr != other.ptr; }
		const Pereche<K, V>& operator*() const { return *ptr; }
	};
	iterator begin() const { return iterator(v); }
	iterator end() const { return iterator(v + count); }
};

