# Домашнее задание к уроку «Свойства хорошего кода. Принципы DRY и SOLID»

### Цель задания
Выполнив задание, вы:
- научитесь находить нарушения принципов SOLID;
- научитесь исправлять их;
- убедитесь, что хороший код может быть короче и понятнее.
---

### Код к заданию

```
#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};

class Data : public Printable
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };

    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string printAsHTML() const override
    {
        if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + data_ + "<html/>";
    }
    std::string printAsText() const override
    {
        if (format_ != Format::kText) {
            throw std::runtime_error("Invalid format!");
        }
        return data_;
    }
    std::string printAsJSON() const override
    {
        if (format_ != Format::kJSON) {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
    Format format_;
};

void saveTo(std::ofstream &file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

void saveToAsHTML(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kHTML);
}

void saveToAsJSON(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kJSON);
}

void saveToAsText(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kText);
}
```

### [Задание 1](01)

В приведённом выше коде есть нарушения некоторых принципов SOLID.

Ваша задача найти и перечислить нарушенные принципы и указать, в чём именно состоит нарушение.

<details> 
  <summary>Подсказки</summary>
  
   В коде нарушены три принципа SOLID:
  
   - подстановки Барбары Лисков,

   - открытости/закрытости,
  
   - разделения интерфейса.
</details>

------

### [Задание 2](02)

Нужно переписать код так, чтобы он соответствовал принципам SOLID. Не бойтесь переименовывать сущности, добавлять новые или удалять старые. 

В финальной версии должны сохраниться:

- функции для сохранения данных в разных форматах,
- логика по форматированию данных.

<details> 
  <summary>Подсказки</summary>
  
  - Функция saveTo не должна ничего знать о формате данных.
  
  - Попробуйте разделить интерфейс Printable на несколько более специализированных интерфейсов.
  
  - Класс Data могут наследовать несколько потомков в зависимости от формата данных.
</details>
------
