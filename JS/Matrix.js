class Matrix {
  #matrix = [];

  constructor(matrix) {
    this.#matrix = matrix;
  }

  rotateRight() {
    const transposed = this.#matrix[0].map((_, colIndex) =>
      this.#matrix.map((row) => row[colIndex])
    );

    this.#matrix = transposed.map((row) => row.reverse());
  }

  rotateLeft() {
    const transposed = this.#matrix[0].map((_, colIndex) =>
      this.#matrix.map((row) => row[colIndex])
    );

    this.#matrix = transposed.reverse();
  }

  get matrix() {
    return this.#matrix;
  }
}
