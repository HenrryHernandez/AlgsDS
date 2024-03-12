class MinHeap {
  #heap = [];

  constructor() {}

  push(value) {
    this.#heap.push(value);
    this.#heapifyUp();
  }

  pop() {
    if (this.#heap.length === 0) return null;

    const minValue = this.#heap[0];
    this.#heap[0] = this.#heap.pop();
    this.#heapifyDown(0);

    return minValue;
  }

  top() {
    if (this.#heap.length === 0) return null;

    const minValue = this.#heap[0];

    return minValue;
  }

  #heapifyUp() {
    let currentIndex = this.#heap.length - 1;

    while (currentIndex > 0) {
      const parentIndex = Math.floor((currentIndex - 1) / 2);

      if (this.#heap[currentIndex] < this.#heap[parentIndex]) {
        [this.#heap[currentIndex], this.#heap[parentIndex]] = [
          this.#heap[parentIndex],
          this.#heap[currentIndex],
        ];

        currentIndex = parentIndex;
      } else {
        break;
      }
    }
  }

  #heapifyDown(index) {
    let currentIndex = index;

    while (true) {
      const leftChildIndex = 2 * currentIndex + 1;
      const rightChildIndex = 2 * currentIndex + 2;
      let smallestChildIndex = currentIndex;

      if (
        leftChildIndex < this.#heap.length &&
        this.#heap[leftChildIndex] < this.#heap[smallestChildIndex]
      ) {
        smallestChildIndex = leftChildIndex;
      }

      if (
        rightChildIndex < this.#heap.length &&
        this.#heap[rightChildIndex] < this.#heap[smallestChildIndex]
      ) {
        smallestChildIndex = rightChildIndex;
      }

      if (currentIndex !== smallestChildIndex) {
        [this.#heap[currentIndex], this.#heap[smallestChildIndex]] = [
          this.#heap[smallestChildIndex],
          this.#heap[currentIndex],
        ];
        currentIndex = smallestChildIndex;
      } else {
        break;
      }
    }
  }
}
