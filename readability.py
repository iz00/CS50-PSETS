def main():
    text = input("Text: ")

    words = text.split()

    text = " ".join(words)

    letters_count = 0

    for c in text:
        if c.isalpha():
            letters_count += 1

    if letters_count == 0:
        words_count = 0
        sentences_count = 0
    else:
        words_count = len(words)
        sentences_count = text.count(".") + text.count("!") + text.count("?")

    index = calculate_index(letters_count, words_count, sentences_count)

    print(get_grade(index))


def calculate_index(letters, words, sentences):
    L = letters / words * 100
    S = sentences / words * 100

    return round(0.0588 * L - 0.296 * S - 15.8)


def get_grade(n):
    if n < 1:
        return "Before grade 1"

    if n > 16:
        return "Grade 16+"

    return f"Grade {n}"


main()
