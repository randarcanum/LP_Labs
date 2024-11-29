public abstract class Employee {
    private final String first_name, last_name, social_security_number;
    private final Date birth_date;

    public Employee(String first_name, String last_name, String social_security_number, Date birth_date) {
        this.first_name = first_name;
        this.last_name = last_name;
        this.social_security_number = social_security_number;
        this.birth_date = birth_date;
    }
    public String get_first_name() {
        return first_name;
    }
    public String get_last_name() {
        return last_name;
    }
    public String get_social_security_number() {
        return social_security_number;
    }
    public Date get_birth_date() {
        return birth_date;
    }
    @Override
    public String toString() {
        return String.format("%s: %s %s%n%s: %s%n%s: %s",
            "employee", get_first_name(), get_last_name(),
            "social security number", get_social_security_number(),
            "birth date", get_birth_date());
    }
    public abstract double earnings();
}