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
			virtual NeuralNetwork_ns::output_t operator()(NeuralNetwork_ns::output_t);
			virtual NeuralNetwork_ns::output_t derivative(NeuralNetwork_ns::output_t);
		};

		class Sigmoid : IActivationFunction
		{
		public:
			NeuralNetwork_ns::output_t operator()(NeuralNetwork_ns::output_t) override;
			NeuralNetwork_ns::output_t derivative(NeuralNetwork_ns::output_t) override;
		};

		class Identity : IActivationFunction
		{
		public:
			NeuralNetwork_ns::output_t operator()(NeuralNetwork_ns::output_t) override;
			NeuralNetwork_ns::output_t derivative(NeuralNetwork_ns::output_t) override;
		};

		class TanH : IActivationFunction
		{
		public:
			NeuralNetwork_ns::output_t operator()(NeuralNetwork_ns::output_t) override;
			NeuralNetwork_ns::output_t derivative(NeuralNetwork_ns::output_t) override;
		};

	}

}

#endif // NEURALNETWORK_PUBLIC_ACTIVATION_HPP
