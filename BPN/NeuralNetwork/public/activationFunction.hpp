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
			virtual NeuralNetwork_ns::numeric operator()(NeuralNetwork_ns::numeric);
		};

		class Sigmoid : IActivationFunction
		{
		public:
			NeuralNetwork_ns::numeric operator()(NeuralNetwork_ns::numeric) override;
		};

		class Threshold : IActivationFunction
		{
		private:
			NeuralNetwork_ns::numeric m_Threshhold;
		public:
			NeuralNetwork_ns::numeric operator()(NeuralNetwork_ns::numeric) override;
		};

	}

}

#endif // NEURALNETWORK_PUBLIC_ACTIVATION_HPP
