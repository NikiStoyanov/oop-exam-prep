#pragma once
#include <vector>
#include <utility>
#include <concepts>
#include <stdexcept>

template <typename T>
concept EqualityComparable = requires (const T& lhs, const T& rhs) {
	{ lhs == rhs } -> std::convertible_to<bool>;
	{ lhs != rhs } -> std::convertible_to<bool>;
};

// template <EqualityComparable T>
template <typename T>
requires std::copyable<T> && std::equality_comparable<T>
class Inventory {
private:
	std::vector<std::pair<T, unsigned>> items;

public:
	void add(const T& item, unsigned quantity);
	void remove(const T& item, unsigned quantity);
	bool contains(const T& item) const;
	unsigned countOfDistinctItems() const;
	unsigned countOfAllItems() const;
	bool isEmpty() const;

	unsigned operator[](const T& item) const;

	Inventory& operator+=(const T& item);
	Inventory& operator-=(const T& item);

	Inventory& operator++();
	Inventory operator++(int dummy);

	Inventory& operator--();
	Inventory operator--(int dummy);	

	friend Inventory operator+(const Inventory& lhs, const Inventory& rhs) {
		Inventory result = lhs;

		for (const auto& pair : rhs.items) {
			result.add(pair.first, pair.second);
		}

		return result;
	}
};

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
void Inventory<T>::add(const T& item, unsigned quantity) {
	if (quantity == 0) {
		throw std::invalid_argument("Quantity must be positive.");
	}

	auto it = std::find_if(items.begin(), items.end(), [&item](const std::pair<T, unsigned>& pair) {
		return pair.first == item;
		});

	if (it != items.end()) {
		it->second += quantity;
	}
	else {
		items.push_back({ item, quantity });
	}
}

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
void Inventory<T>::remove(const T & item, unsigned quantity) {
	if (quantity == 0) {
		throw std::invalid_argument("Quantity must be positive.");
	}

	auto it = std::find_if(items.begin(), items.end(), [&item](const std::pair<T, unsigned>& pair) {
		return pair.first == item;
		});

	if (it == items.end()) {
		throw std::invalid_argument("No item found.");
	}

	if (quantity < it->second) {
		it->second -= quantity;
	} else if (quantity == it->second) {
		items.erase(it);
	} else {
		throw std::invalid_argument("There are less items available.");
	}
}

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
bool Inventory<T>::contains(const T& item) const {
	auto it = std::find_if(items.cbegin(), items.cend(), [&item](const std::pair<T, unsigned>& pair) {
		return pair.first == item;
		});

	return it != items.cend();
}

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
unsigned Inventory<T>::countOfDistinctItems() const {
	return items.size();
}

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
unsigned Inventory<T>::countOfAllItems() const {
	unsigned size = 0;

	for (const auto& item : items) {
		size += item.second;
	}

	return size;
}

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
bool Inventory<T>::isEmpty() const {
	return items.empty();
}

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
unsigned Inventory<T>::operator[](const T& item) const {
	auto it = std::find_if(items.cbegin(), items.cend(), [&item](const std::pair<T, unsigned>& pair) {
		return pair.first == item;
		});

	return (it != items.cend()) ? it->second : 0;
}

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
Inventory<T>& Inventory<T>::operator+=(const T& item) {
	add(item, 1);
	return *this;
}

template<typename T>
requires std::copyable<T> && std::equality_comparable<T>
Inventory<T>& Inventory<T>::operator-=(const T& item) {
	remove(item, 1);
	return *this;
}

template<typename T>
	requires std::copyable<T>&& std::equality_comparable<T>
Inventory<T>& Inventory<T>::operator++() {
	for (auto& pair : items) {
		pair.second++;
	}

	return *this;
}

template<typename T>
requires std::copyable<T>&& std::equality_comparable<T>
Inventory<T> Inventory<T>::operator++(int) {
	Inventory<T> oldState = *this;
	++(*this);
	return oldState;
}

template<typename T>
requires std::copyable<T>&& std::equality_comparable<T>
Inventory<T>& Inventory<T>::operator--() {
	for (auto& pair : items) {
		pair.second--;
	}

	std::erase_if(items, [](const std::pair<T, unsigned>& pair) {
		return pair.second == 0;
		});

	return *this;
}

template<typename T>
requires std::copyable<T>&& std::equality_comparable<T>
Inventory<T> Inventory<T>::operator--(int) {
	Inventory<T> oldState = *this;
	--(*this);
	return oldState;
}