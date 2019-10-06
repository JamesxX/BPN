#ifndef NEURALNETWORK_PUBLIC_ACTIVATION_HPP
#define NEURALNETWORK_PUBLIC_ACTIVATION_HPP

#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>

namespace NeuralNetwork_ns
{

	namespace ActivationFunction
	{

		class IActivationFunction
		{
		public:
			virtual NeuralNetwork_ns::matrix_component_t operator()(NeuralNetwork_ns::matrix_component_t);
			virtual NeuralNetwork_ns::matrix_component_t derivative(NeuralNetwork_ns::matrix_component_t);
		};

#define ActivationFunctionPreprocessorDeclaration(name) \
class name : IActivationFunction \
{ \
public: \
	NeuralNetwork_ns::matrix_component_t operator()(NeuralNetwork_ns::matrix_component_t) override; \
	NeuralNetwork_ns::matrix_component_t derivative(NeuralNetwork_ns::matrix_component_t) override; \
} \

		ActivationFunctionPreprocessorDeclaration(Sigmoid);
		ActivationFunctionPreprocessorDeclaration(Identity);
		ActivationFunctionPreprocessorDeclaration(TanH);

#undef ActivationFunctionPreprocessorDeclaration

	}

}

#endif // NEURALNETWORK_PUBLIC_ACTIVATION_HPP
