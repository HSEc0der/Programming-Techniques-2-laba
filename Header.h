#ifndef Header
#define Header
#include <string>

namespace N {
	class OurClass {
	private:
		int home;
		int flat;
		int room;
		int s;
		int people;
		std::string fio;
	public:
		// конструктор
		OurClass(const std::string& str);

		//пустой конструктор
		OurClass();

		//возвращает номер дома
		int getHome();

		//возвращает номер квартиры
		int getFlat();

		//возвращает площадь
		int getSquare();

		// возвращает число людей
		int getPeople();

		//возврашает ФИО
		std::string getFio();

		//возвращает всю строку
		std::string AllString();

		// выводит только те поля, по которым была сортировка
		std::string showSorted();

		//работает также, как и конструктор
		void setAll(std::string& str);

		// перегрузка оператора сравнения БОЛЬШЕ 
		friend bool operator>(const OurClass& left, const OurClass& right);


		// перегрузка оператора сравнения БОЛЬШЕ ИЛИ РАВНО
		friend bool operator>=(const OurClass& left, const OurClass& right);


		// перегрузка оператора МЕНЬШЕ
		friend bool operator<(const OurClass& left, const OurClass& right);


		//перегрузка оператора МЕНЬШЕ ИЛИ РАВНО
		friend bool operator<=(const OurClass& left, const OurClass& right);

	}; // end our_class
} // end namespace N
#endif
