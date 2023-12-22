import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    people = read_people_database(sys.argv[1])

    # TODO: Read DNA sequence file into a variable
    dna_sequence = read_dna_sequence(sys.argv[2])

    STRs = list(people[0].keys())
    STRs.pop(0)

    # TODO: Find longest match of each STR in DNA sequence
    STRs_count = {}
    for STR in STRs:
        STRs_count[STR] = str(longest_match(dna_sequence, STR))

    # TODO: Check database for matching profiles
    for person in people:
        person_STRs = list(person.keys())
        person_STRs.pop(0)
        match = True
        for STR in person_STRs:
            if STRs_count[STR] != person[STR]:
                match = False
                break
        if match:
            print(person["name"])


def read_people_database(filename):
    people = []
    try:
        file = open(filename)
    except FileNotFoundError:
        sys.exit("File not found")
    else:
        file_reader = csv.DictReader(file)

        for person in file_reader:
            people.append(person)

        file.close()
        return people


def read_dna_sequence(filename):
    try:
        file = open(filename)
    except FileNotFoundError:
        sys.exit("File not found")
    else:
        dna_sequence = file.read()
        file.close()

        return dna_sequence


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
