#include <iostream>
#include <string>
using namespace std;
class FIO {
public:
	std::string FirstName;
	std::string MiddleName;
	std::string LastName;
	FIO() { // êëàññ ôèî ïàöèåíòà
		FirstName = "alla";
		MiddleName = "pugazeva";
		LastName = "andreevna";
	}
	FIO(std::string _firstName, std::string _MiddleName, std::string _lastName) {
		FirstName = _firstName;
		MiddleName = _MiddleName;
		LastName = _lastName;
	}
	FIO(FIO& g) {
		FirstName = g.FirstName;
		MiddleName = g.MiddleName;
		LastName = g.LastName;
	}
	FIO& operator=(const FIO& f) { // ïåðåãðóçêà îïåðàòîðà =
		if (this != &f) {
			this->FirstName = f.FirstName;
			this->MiddleName = f.MiddleName;
			this->LastName = f.LastName;
			return *this;
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const FIO& f);
	friend std::istream& operator>>(std::istream& in, FIO& f);
};
std::ostream& operator<<(std::ostream& out, const FIO& f) {   // ïåðåãðóçêà âûâîäà
	out << "<" << f.FirstName << f.MiddleName << f.LastName << ">";
	return out;
};
std::istream& operator>>(std::istream& in, FIO& f) { // ïåðåãðóçêà ââîäà
	in >> f.FirstName >> f.MiddleName >> f.LastName;
	return in;
};
class Phone { // íîìåð òåëåôîíà
public:
	std::string phone;
	Phone() {
		phone = "null";
	}
	Phone(std::string _phone) {
		phone = _phone;
	}
	Phone(Phone& g) {
		phone = g.phone;
	}

	Phone& operator=(const Phone& g) {
		if (this != &g) {
			this->phone = g.phone;
			return *this;
		}
		else return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const Phone& p);
	friend std::istream& operator>>(std::istream& in, Phone& p);

	std::string Set_phone(std::string _phone) {
		phone = _phone;
	}
	std::string Get_phone() {
		return phone;
	}
	Phone& operator=(Phone& p) {
		phone = p.Get_phone();
		return *this;
	}
};
std::ostream& operator<<(std::ostream& out, const Phone& g) {
	out << "<" << g.phone<< ">";
	return out;
};
std::istream& operator>>(std::istream& in, Phone& g) {
	in >> g.phone;
	return in;
};
class Data { // Äàòà ïðè¸ìà
public:
	int day;
	int month;
	int year;
	Data() {
		day = 0;
		month = 0;
		year = 0;
	}

	Data(int _day, int _month, int _year) {
		day = _day;
		month = _month;
		year = _year;
	}
	Data(Data& data) {
		day = data.day;
		month = data.month;
		year = data.year;
	}

	void Set_day(int _day) {
		day = _day;
	}

	int Get_day() const {
		return day;
	}

	void Set_month(int _month) {
		month = _month;
	}

	int Get_month() const {
		return month;
	}

	void Set_year(int _year) {
		year = _year;
	}

	int Get_year() const {
		return year;
	}

	friend std::ostream& operator<<(std::ostream& out, const Data& date);
	friend std::istream& operator>>(std::istream& input, Data& date);
};
std::ostream& operator<<(std::ostream& out, const Data& date) {
	out << date.day << date.month << date.year;
	return out;
};
std::istream& operator>>(std::istream& in, Data& date) {
	in >> date.day >> date.month >> date.year;
	return in;
};
class Adress {
public:
	std::string street;
	std::string home;
	std::string apartament;
	Adress() {
		street = "no";
		home = "no";
		apartament = "no";
	}
	Adress(std::string _street, std::string _home, std::string _apartament) {
		street = _street;
		home = _home;
		apartament = _apartament;
	}
	Adress(const Adress& ad) {
		street = ad.street;
		home = ad.home;
		apartament = ad.apartament;
	}

	friend std::ostream& operator<<(std::ostream& out, const Adress& ad);
	friend std::istream& operator>>(std::istream& in, Adress& ad);

	std::string Set_street(std::string _street) {
		street = _street;
	}
	std::string Get_street()const {
		return street;
	}
	std::string Set_home(std::string _home) {
		home = _home;
	}
	std::string Get_home()const {
		return home;
	}
	std::string Set_apartament(std::string _apartament) {
		apartament = _apartament;
	}
	std::string Get_apartament() const {
		return apartament;
	}
	Adress& operator=(const Adress& a) {
		street = a.Get_street();
		home = a.Get_home();
		apartament = a.Get_apartament();
		return *this;
	}
};
std::ostream& operator<<(std::ostream& out, const Adress& ad) {
	out << "<" << ad.street << ad.home << ad.apartament << ">";
	return out;
};
std::istream& operator>>(std::istream& in, Adress& ad) {
	in >> ad.street >> ad.home >> ad.apartament;
	return in;
};
class Doctor {
public:
	Phone doctorphone;
	FIO doctorfio;
	Doctor() {

	}
	Doctor( std::string _FirstName, std::string _MiddleName, std::string _LastName, std::string _phone) {
		doctorfio.FirstName = _FirstName;
		doctorfio.MiddleName = _MiddleName;
		doctorfio.LastName = _LastName;
		doctorphone = _phone;
	}
	Doctor(Doctor& doc) {
		doctorfio = doc.doctorfio;
		doctorphone = doc.doctorphone;
	}
	Doctor& operator=(const Doctor& doc) {
		doctorfio = doc.doctorfio;
		doctorphone = doc.doctorphone;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const Doctor& doc);
	friend std::istream& operator>>(std::istream& in, Doctor& doc);
};
std::ostream& operator<<(std::ostream& out, const Doctor& doc) {
	out << doc.doctorfio<<doc.doctorphone;
	return out;
};
std::istream& operator>>(std::istream& in, Doctor& doc) {
	in >> doc.doctorfio>>doc.doctorphone;
	return in;
};
enum Servis { primaryreception, readmission, bloodtest, ultrasound, No };// ïåðâè÷íûé ïðèåì. âòîðîé ïðèåì. òåñò êðîâè. óçè

class Patient {
private:
	FIO patientFio;
	Doctor doctor;
	Phone patientPhone;
	Servis servis;
	Data date;
public:
	Patient() {
		servis = { No };
	}
	Patient(FIO _patientFio, Doctor _doctor,Phone _patientPhone, Servis _serv) {
		patientFio = _patientFio;
		doctor = _doctor;
		patientPhone = _patientPhone;
		servis = _serv;
	}
	Patient(Patient& dor) {
		patientFio = dor.patientFio;
		doctor = dor.doctor;
		patientPhone = dor.patientPhone;
		servis = dor.servis;
	}
	FIO Get_patientFio() {
		return patientFio;
	}
	Doctor Get_doctor() {
		return doctor;
	}
	Phone Get_patientPhone() {
		return patientPhone;
	}
	friend std::ostream& operator<<(std::ostream& out, const Patient& dor);
	friend std::istream& operator>> (std::istream& in, Patient& dor);

	Patient& operator=(Patient& dor) {
		patientFio = dor.Get_patientFio();
		doctor = dor.Get_doctor();
		patientPhone = dor.Get_patientPhone();
		return *this;
	};
	friend std::istream& operator>>(std::istream& in, Patient& dor) {
		std::cout << "\n1.primaryreception\n2.readmission\n3.bloodtest\n4.ultrasound";
		int n = 0;
		in >> n;
		if (n == 1) dor.servis = primaryreception;
		else if (n == 2) dor.servis = readmission;
		else if (n == 3) dor.servis = bloodtest;
		else if (n == 4) dor.servis = ultrasound;
		std::cout << "Enter the FIO:";
		in >> dor.patientFio;
		std::cout << "Enter the Doctor:";
		in >> dor.doctor;
		std::cout << "Enter the Phone:";
		in >> dor.patientPhone;
	};
	friend std::ostream& operator<<(std::ostream& out, const Patient& dor) {
		if (dor.servis == primaryreception) out << "servis - primaryreception";
		else if (dor.servis == readmission) out << "servis - readmission";
		else if (dor.servis == bloodtest)  out << "servis - bloodtest";
		else if (dor.servis == ultrasound)  out << "servis - ultrasound";
		out << "Fio:" << dor.patientFio;
		out << "Doctor:" << dor.doctor;
		out << "PatientPhone:" << dor.patientPhone;
		out << "servis:" << dor.servis;
	};
	class receipt{
		int a;
		int size;
		Patient* chek;
	public:
		receipt() {
			a = 1;
			size = 0;
			chek = new Patient[a];//âûäåëåíèå ïàìÿòè äëÿ ïàöèåíòà
		}
		receipt(int _a) {
			a = _a;
			size = 0;
			chek = new Patient[a];
		}
		receipt(const receipt& m) {
			a = m.a;
			size = m.size;
			chek = m.chek;
		}
		~receipt() {
			delete[] chek;
			chek = nullptr;
		}
		void payment(Patient& m) {
			if (size >= a) {
				int new_a = a + 1;
				Patient* new_a = new Patient[new_a];
				for (int i = 0; i < a; i++) {
					chek[i] = new_a[i];
				}
				delete[] chek;
				chek = new_a;
				a = new_a;
			}
			chek[size] = m;
			size++;
		}

		Patient* get_card() const {
			return chek;
		}
		int get_size() {
			return size;
		}
	};
	int main() {
		Patient patient;
		receipt	Receipt;
		std::cin >> patient;
		Receipt.payment(patient);

};

	
