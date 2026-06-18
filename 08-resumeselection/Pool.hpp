#pragma once
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
class Pool {
protected:
	std::vector<T> items;

public:
	void add(T item);
	void removeItem(std::function<bool(const T& item)> func);
	std::vector<T> filter(std::function<bool(const T& item)> func) const;
	T* findFirst(std::function<bool(const T& item)> func);
	const T* findFirst(std::function<bool(const T& item)> func) const;
	unsigned size() const;
	bool isEmpty() const;
};

template<typename T>
void Pool<T>::add(T item) {
	items.push_back(std::move(item));
}

template<typename T>
void Pool<T>::removeItem(std::function<bool(const T & item)> func) {
	std::erase_if(items, func);
}

template<typename T>
std::vector<T> Pool<T>::filter(std::function<bool(const T & item)> func) const {
	std::vector<T> filtered;

	for (const auto& item : items) {
		if (func(item)) {
			filtered.push_back(item);
		}
	}

	return filtered;
}

template<typename T>
T* Pool<T>::findFirst(std::function<bool(const T& item)> func) {
	auto it = std::find_if(items.begin(), items.end(), func);

	return (it == items.end()) ? nullptr : &(*it);
}

template<typename T>
const T* Pool<T>::findFirst(std::function<bool(const T& item)> func) const {
	auto it = std::find_if(items.cbegin(), items.cend(), func);

	return (it == items.cend()) ? nullptr : &(*it);
}

template<typename T>
unsigned Pool<T>::size() const {
	return items.size();
}

template<typename T>
bool Pool<T>::isEmpty() const {
	return items.empty();
}
