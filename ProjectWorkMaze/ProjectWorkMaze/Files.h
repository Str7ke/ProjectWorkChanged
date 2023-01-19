#pragma once

void ReadAllText(FILE* stream) {
	while (!feof(stream)) {
		int symbol = fgetc(stream);
		cout << (char)symbol;
	}
	cout << endl;
}

