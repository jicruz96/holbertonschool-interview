#!/usr/bin/python3
""" Module defininf rotate_2d_matrix """


def rotate_2d_matrix_in_place(matrix):
    """rotates a 2d n * n matrix clockwise

    This approach rotates the matrix in place, so no new memory is used.
    Therefore, this approach has a O(1) space complexity and a O(n^2) time
    complexity, where n is the row length of the matrix

    Args:
        matrix (List[List[int]]): 2d n * n matrix
    """
    for start in range(int(len(matrix) / 2)):
        end = len(matrix) - start - 1

        # Rotate four positions
        for i in range(end - start):
            # Save top left number
            tmp = matrix[start][start + i]
            # In top left position, place bottom left number
            matrix[start][start + i] = matrix[end - i][start]
            # In bottom left position, save bottom right number
            matrix[end - i][start] = matrix[end][end - i]
            # In bottom right position, save top right number
            matrix[end][end - i] = matrix[start + i][end]
            # In top right position, save former top left number
            matrix[start + i][end] = tmp


def rotate_2d_matrix_simple(matrix):
    """rotates a 2d matrix clockwise

    This approach creates the rotated matrix and then reassigns the rows to the
    original matrix. Therefore, it has a O(n) space complexity. The process
    to create the rotated matrix has a O(n^2) time complexity where n is the
    row length of the matrix.

    Args:
        matrix (List[List[int]]): 2d matrix
    """

    row_indices_reversed = range(len(matrix) - 1, -1, -1)
    new = []
    for col in range(len(matrix)):
        new.append([matrix[row][col] for row in row_indices_reversed])

    for i in range(len(matrix)):
        matrix[i] = new[i]


def rotate_2d_matrix(matrix):
    rotate_2d_matrix_in_place(matrix)


if __name__ == "__main__":
    matrices = [
        [
            [1,  2,  3,  4],
            [5,  6,  7,  8],
            [9, 10, 11, 12],
            [13, 14, 15, 16]
        ],
        [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ],
        [
            [1, 2],
            [3, 4]
        ],
        [
            [1]
        ],
        [
            [1,  2,  3,  4,  5],
            [6,  7,  8,  9, 10],
            [11, 12, 13, 14, 15],
            [16, 17, 18, 19, 20],
            [21, 22, 23, 24, 25]
        ]
    ]

    answers = [
        [
            [13,  9,  5,  1],
            [14, 10,  6,  2],
            [15, 11,  7,  3],
            [16, 12,  8,  4]
        ],
        [
            [7, 4, 1],
            [8, 5, 2],
            [9, 6, 3]
        ],
        [
            [3, 1],
            [4, 2]
        ],
        [
            [1]
        ],
        [
            [21, 16, 11,  6,  1],
            [22, 17, 12,  7,  2],
            [23, 18, 13,  8,  3],
            [24, 19, 14,  9,  4],
            [25, 20, 15, 10,  5]
        ]
    ]

    originals = matrices.copy()
    for i in range(len(matrices)):
        rotate_2d_matrix(matrices[i])
        if matrices[i] != answers[i]:
            print('Test failed for matrix {}'.format(originals[i]))
            print('Expected: {}'.format(answers[i]))
            print('Got:      {}'.format(matrices[i]))
        else:
            print('✅')
