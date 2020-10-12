import java.util.Arrays;

public class MergeSort<T extends Comparable<T>> {

	public void sort(T[] array, int leftIndex, int rightIndex) {
		if (leftIndex < rightIndex) {
			int middle = (leftIndex + rightIndex) / 2;
			sort(array, leftIndex, middle);
			sort(array, middle + 1, rightIndex);
			merge(array, leftIndex, middle, rightIndex);
		}
	}
	
	private void merge(T[] array, int begin, int mid, int end) {
		T[] aux = Arrays.copyOf(array, array.length);
		
		int i = begin;
		int j = mid + 1;
		int k = begin;
		
		while (i <= mid && j <= end) {
			if (aux[i].compareTo(aux[j]) < 0) {
				array[k] = aux[i];
				i++;
			} else {
				array[k] = aux[j];
				j++;
			}
			k++;
		}
		
		while (i <= mid) {
			array[k++] = aux[i++];
		}
		
		while (j <= end) {
			array[k++] = aux[j++];
		}
	}
}
