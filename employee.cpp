#include "employee.h"

AbstractEmployee::AbstractEmployee(const std::string& fn, const std::string& ln, const std::string& j)
: first_name_(fn), last_name_(ln), job_(j)
{}

AbstractEmployee::AbstractEmployee(AbstractEmployee const &e)
: first_name_(e.first_name_), last_name_(e.last_name_), job_(e.job_)
{}

AbstractEmployee::~AbstractEmployee() {}

void AbstractEmployee::showAll() const
{
	std::cout << "First name: " << first_name_ << std::endl;
	std::cout << "Last name: " << last_name_ << std::endl;
	std::cout << "Job: " << job_ << std::endl;
}

void AbstractEmployee::setAll()
{
	std::cout << "Enter first name: ";
	std::cin >> first_name_;
	std::cout << "Enter last name: ";
	std::cin >> last_name_;
	std::cout << "Enter job: ";
	std::cin >> job_;
}

std::ostream& operator<<(std::ostream& os, const AbstractEmployee& e)
{
	os << "First name: " << e.first_name_  << '\n' << "Last name: " << e.last_name_ << '\n';
	return os;
}

Employee::Employee(const std::string& fn, const std::string& ln, const std::string& j)
: AbstractEmployee(fn, ln, j)
{}

void Employee::showAll() const
{
	AbstractEmployee::showAll();
}

void Employee::setAll()
{
	AbstractEmployee::setAll();
}

Manager::Manager(const std::string& fn, const std::string& ln,const std::string& j, int ico)
: AbstractEmployee(fn, ln, j), in_charge_of_(ico)
{}

Manager::Manager(const AbstractEmployee& e, int ico)
: AbstractEmployee(e), in_charge_of_(ico)
{}

Manager::Manager(const Manager& m)
: AbstractEmployee(m), in_charge_of_(m.in_charge_of_)
{}

void Manager::showAll() const
{
	AbstractEmployee::showAll();
	std::cout << "Number of employees manager is in charge of: " << in_charge_of_ << std::endl;
}

void Manager::setAll()
{
	AbstractEmployee::setAll();
	std::cout << "Enter number of employees manager is in charge of: ";
	std::cin >> in_charge_of_;
}

Fink::Fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
: AbstractEmployee(fn, ln, j), reports_to_(rpo)
{}

Fink::Fink(const AbstractEmployee& e, const std::string& rpo)
: AbstractEmployee(e), reports_to_(rpo)
{}

Fink::Fink(const Fink & e)
: AbstractEmployee(e), reports_to_(e.reports_to_)
{}

void Fink::showAll() const
{
	AbstractEmployee::showAll();
	std::cout << "Person, who he reports to: " << reports_to_ << std::endl;
}

void Fink::setAll()
{
	AbstractEmployee::setAll();
	std::cout << "Enter person, who he reports to: ";
	std::cin >> reports_to_;
}

HighFink::HighFink(const std::string& fn, const std::string& ln,const std::string& j, const std::string& rpo, int ico)
: AbstractEmployee(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo)
{}

HighFink::HighFink(const AbstractEmployee& e, const std::string& rpo, int ico)
: AbstractEmployee(e), Manager(e, ico), Fink(e, rpo)
{}

HighFink::HighFink(const Fink& f, int ico)
: AbstractEmployee(f), Manager(f, ico), Fink(f)
{}

HighFink::HighFink(const Manager& m, const std::string& rpo)
: AbstractEmployee(m), Manager(m), Fink(m, rpo)
{}

HighFink::HighFink(const HighFink& h)
: AbstractEmployee(h), Manager(h), Fink(h)
{}

void HighFink::showAll() const
{
	AbstractEmployee::showAll();
	std::cout << "Number of employees manager is in charge of: " << inChargeOf() << std::endl;
	std::cout << "Person, who he reports to: " << reportsTo() << std::endl;
}

void HighFink::setAll()
{
	int			inc;
	std::string	rt;

	AbstractEmployee::setAll();
	std::cout << "Enter number of employees manager is in charge of: ";
	std::cin >> inc; 
	setInChargeOf(inc);
	std::cout << "Enter person, who he reports to: ";
	std::cin >> rt;
	setReportsTo(rt);
}

