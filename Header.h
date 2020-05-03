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
		// �����������
		OurClass(const std::string& str);

		//������ �����������
		OurClass();

		//���������� ����� ����
		int getHome();

		//���������� ����� ��������
		int getFlat();

		//���������� �������
		int getSquare();

		// ���������� ����� �����
		int getPeople();

		//���������� ���
		std::string getFio();

		//���������� ��� ������
		std::string AllString();

		// ������� ������ �� ����, �� ������� ���� ����������
		std::string showSorted();

		//�������� �����, ��� � �����������
		void setAll(std::string& str);

		// ���������� ��������� ��������� ������ 
		friend bool operator>(const OurClass& left, const OurClass& right);


		// ���������� ��������� ��������� ������ ��� �����
		friend bool operator>=(const OurClass& left, const OurClass& right);


		// ���������� ��������� ������
		friend bool operator<(const OurClass& left, const OurClass& right);


		//���������� ��������� ������ ��� �����
		friend bool operator<=(const OurClass& left, const OurClass& right);

		// ���������� ��������� ������������
		OurClass& operator=(const OurClass& other) {
			home = other.home;
			flat = other.flat;
			s = other.s;
			fio = other.fio;
			room = other.room;
			people = other.people;
			return *this;
		}
	}; // end our_class
} // end namespace N
#endif
