#ifndef NEURALNETWORK_PUBLIC_FORWARD_HPP
#define NEURALNETWORK_PUBLIC_FORWARD_HPP

#include <NeuralNetwork/public/library.hpp>
#include <vector>
#include <dependencies/eigen/Eigen/Dense>

#define NeuralNetwork_ns NeuralNetwork
namespace NeuralNetwork_ns
{

	typedef double numeric_t;
	typedef numeric_t numeric;
	typedef numeric_t matrix_component_t;

	typedef Eigen::Matrix<matrix_component_t, Eigen::Dynamic, Eigen::Dynamic> MatrixXd;
	typedef Eigen::Matrix<matrix_component_t, 1, Eigen::Dynamic> Matrix1Rowd;
	typedef Eigen::Matrix<matrix_component_t, Eigen::Dynamic, 1> Matrix1Cold;

	typedef Matrix1Cold layer_input_t;
	typedef MatrixXd layer_weights_t;
	typedef Matrix1Cold layer_biases_t;
	typedef Matrix1Cold layer_output_t;

	namespace Layer {
		class ILayer;
		class InputLayer;
		class DenseLayer;
		class OutputLayer;
	};

	namespace Network
	{
		class MLP;
		typedef _STD vector<Layer::ILayer> layer_list_t;
	};

	typedef _STD size_t neuron_id_t;

	namespace ActivationFunction
	{
		class IActivationFunction;
		class Sigmoid;
		class Identity;
		class TanH;
	};

};

#endif // NEURALNETWORK_PUBLIC_FORWARD_HPP
